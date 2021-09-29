package main

import (
	"errors"
	"fmt"
	"math/rand"
	"time"
)

type Shop struct {
	queue SeatQueue
}

type Barber struct{}

type SeatQueue struct {
	seats []int
	cap   int
}

var shop = Shop{queue: CreateSeats(15)}

func main() {
	quit := make(chan struct{})
	customerChannel := make(chan int, 1)
	customerReady := make(chan struct{}, 1)
	queueSync := make(chan struct{}, 1)
	customerServed := make(chan struct{}, 1)

	queueSync <- struct{}{}
	var numberOfCustomers = 25
	go customer(customerChannel, customerReady, quit, queueSync)
	go barber(customerReady, quit, queueSync, customerServed)
	go checkIfEveryoneIsServed(customerServed, quit, numberOfCustomers)

	for customer := 1; customer <= numberOfCustomers; customer++ {
		randomDelay()
		customerChannel <- customer
	}

	<-quit
}

func checkIfEveryoneIsServed(customerServed, quit chan struct{}, customers int) {
	counter := 0
	for {
		<-customerServed
		counter++
		if counter == customers {
			break
		}
	}
	quit <- struct{}{}
	quit <- struct{}{}
}

func customer(customerChan chan int, cReady, quit, queueSync chan struct{}) {
	for {
		select {
		case customer := <-customerChan:
			fmt.Printf("Customer %d came and tries to find place in the queue\n", customer)
			<-queueSync
			err := shop.queue.addCustomer(customer)
			queueSync <- struct{}{}
			if err != nil {
				fmt.Printf("Queue is full, customer %d cannot come\n", customer)
			} else {
				fmt.Printf("Customer %d takes a seat\n", customer)
				cReady <- struct{}{}
			}
		case <-quit:
			break
		}
	}
}

func barber(cReady, quit, queueSync, customerServed chan struct{}) {
	for {
		select {
		case <-cReady:
			<-queueSync
			var customer, err = shop.queue.nextCustomer()
			if err == nil {
				fmt.Printf("Barber is serving customer %d\n", customer)
				fmt.Printf("People in queue: %v\n", shop.queue.seats)
				queueSync <- struct{}{}
				randomDelay()
				fmt.Printf("Serving customer is finished %d\n", customer)
				customerServed <- struct{}{}
			} else {
				queueSync <- struct{}{}
				fmt.Println("There is no customer to call from the queue!")
			}

		case <-quit:
			quit <- struct{}{}
			break
		}
	}
}

func randomDelay() {
	time.Sleep(time.Duration(rand.Intn(100)) * time.Millisecond)
}

func CreateSeats(capacity int) SeatQueue {
	return SeatQueue{
		seats: make([]int, 0),
		cap:   capacity,
	}
}

func (seatOrder *SeatQueue) addCustomer(customer int) error {
	if len(seatOrder.seats) < seatOrder.cap {
		seatOrder.seats = append([]int{customer}, seatOrder.seats...)
		return nil
	} else {
		return errors.New("There are no free seats in the queue")
	}
}

func (seatOrder *SeatQueue) checkAvailibility() bool {
	return len(seatOrder.seats) < seatOrder.cap
}

func (seatOrder *SeatQueue) nextCustomer() (int, error) {
	var val int
	val, seatOrder.seats = seatOrder.seats[0], seatOrder.seats[1:]
	if val == 0 {
		return val, errors.New("There are no customers in the queue")
	} else {
		return val, nil
	}
}
