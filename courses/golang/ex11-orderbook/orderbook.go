package orderbook

type Orderbook struct {
	orders []*Order
}

func New() *Orderbook {
	return &Orderbook{
		orders: make([]*Order, 0),
	}
}

func (orderbook *Orderbook) Match(order *Order) ([]*Trade, *Order) {
	// TODO
	return nil, nil
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
