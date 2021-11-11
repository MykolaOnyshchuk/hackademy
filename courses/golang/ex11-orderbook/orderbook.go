package orderbook

type Orderbook struct {
	orders []*Order
}

func New() *Orderbook {
	return &Orderbook{
		orders: make([]*Order, 0),
	}
}

func (orderbook *Orderbook) Match(order *Order) (trades []*Trade, rejected *Order) {

	if order.Kind == KindMarket {
		trades = orderbook.MarketOrderProcedure(order)
		if order.Volume > 0 {
			rejected = order
		}
	}
	if order.Kind == KindLimit {
		trades = orderbook.LimitOrderProcedure(order)
		if order.Volume > 0 {
			orderbook.orders = append(orderbook.orders, order)
		}
	}

	return
}

func (orderbook *Orderbook) remove(order *Order) {
	for i := 0; i < len(orderbook.orders); i++ {
		if order == orderbook.orders[i] {
			newOrderbook := orderbook.orders[:i]
			for j := i + 1; j < len(orderbook.orders); j++ {
				newOrderbook = append(newOrderbook, orderbook.orders[j])
			}
			orderbook.orders = newOrderbook
			return
		}
	}
}

func (orderbook *Orderbook) ordersManaging(order, storedOrder *Order) (trade *Trade, satisfied bool) {
	trade = &Trade{}

	if order.Volume <= storedOrder.Volume {
		trade.Volume = order.Volume
		trade.Price = storedOrder.Price
		satisfied = true
		storedOrder.Volume = storedOrder.Volume - order.Volume
		order.Volume = 0
		if order.Volume == storedOrder.Volume {
			orderbook.remove(storedOrder)
		}

	} else if order.Volume > storedOrder.Volume {
		trade.Volume = storedOrder.Volume
		trade.Price = storedOrder.Price
		satisfied = false
		order.Volume = order.Volume - storedOrder.Volume
		storedOrder.Volume = 0
		orderbook.remove(storedOrder)
	}

	if order.Side == SideAsk {
		trade.Ask = order
		trade.Bid = storedOrder
	} else if order.Side == SideBid {
		trade.Ask = storedOrder
		trade.Bid = order
	}

	return
}

func (orderbook *Orderbook) bestLimit(order *Order) *Order {
	differentSideOrders := make([]*Order, 0)
	for i := 0; i < len(orderbook.orders); i++ {
		if order.Side == orderbook.orders[i].Side {
			continue
		}
		differentSideOrders = append(differentSideOrders, orderbook.orders[i])
	}
	potentialOrders := differentSideOrders
	if len(potentialOrders) == 0 {
		return nil
	}
	var mostProfitable *Order
	for i := 0; i < len(potentialOrders); i++ {
		mostProfitable = order.bestAskLimit(potentialOrders[i], mostProfitable)
		mostProfitable = order.bestBidLimit(potentialOrders[i], mostProfitable)
	}
	return mostProfitable
}

func (order *Order) bestAskLimit(storedOrder *Order, mostProfitable *Order) *Order {
	if order.Side == SideAsk && order.Price <= storedOrder.Price && (mostProfitable == nil || storedOrder.Price-order.Price > mostProfitable.Price-order.Price) {
		mostProfitable = storedOrder
	}
	return mostProfitable
}

func (order *Order) bestBidLimit(storedOrder *Order, mostProfitable *Order) *Order {
	if order.Side == SideBid && order.Price >= storedOrder.Price && (mostProfitable == nil || order.Price-storedOrder.Price > order.Price-mostProfitable.Price) {
		mostProfitable = storedOrder
	}
	return mostProfitable
}

func (orderbook *Orderbook) LimitOrderProcedure(order *Order) (trades []*Trade) {
	trades = make([]*Trade, 0)

	profitable := orderbook.bestLimit(order)
	for profitable != nil {
		trade, satisfied := orderbook.ordersManaging(order, profitable)
		trades = append(trades, trade)
		if satisfied {
			return
		}
		profitable = orderbook.bestLimit(order)
	}
	return
}

func (orderbook *Orderbook) bestMarket(order *Order) *Order {
	differentSideOrders := make([]*Order, 0)
	for i := 0; i < len(orderbook.orders); i++ {
		if order.Side == orderbook.orders[i].Side {
			continue
		}
		differentSideOrders = append(differentSideOrders, orderbook.orders[i])
	}
	potentialOrders := differentSideOrders
	if len(potentialOrders) == 0 {
		return nil
	}
	var mostProfitable *Order
	for i := 0; i < len(potentialOrders); i++ {

		mostProfitable = order.bestAskLimit(potentialOrders[i], mostProfitable)
		mostProfitable = order.bestAskMarket(potentialOrders[i], mostProfitable)
	}
	return mostProfitable
}

func (order *Order) bestAskMarket(storedOrder *Order, mostProfitable *Order) *Order {
	if order.Side == SideAsk && mostProfitable == nil || storedOrder.Price > mostProfitable.Price {
		mostProfitable = storedOrder
	}
	return mostProfitable
}

func (order *Order) bestBidMarket(storedOrder *Order, mostProfitable *Order) *Order {
	if order.Side == SideBid && mostProfitable == nil || storedOrder.Price < mostProfitable.Price {
		mostProfitable = storedOrder
	}
	return mostProfitable
}

func (orderbook *Orderbook) MarketOrderProcedure(order *Order) (trades []*Trade) {
	trades = make([]*Trade, 0)

	profitable := orderbook.bestMarket(order)
	for profitable != nil {
		trade, satisfied := orderbook.ordersManaging(order, profitable)
		trades = append(trades, trade)
		if satisfied {
			return
		}
		profitable = orderbook.bestMarket(order)
	}
	return
}
