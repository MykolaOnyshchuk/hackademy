package main

import (
	"bufio"
	"fmt"
	"os"
	"time"
)

func worker(id int, jobs <-chan int, results chan<- int, seconds []float64, counter *int) {
	for j := range jobs {
		*counter++
		fmt.Println("worker:", id, "spawning")
		fmt.Println("worker:", id, "sleeping:", seconds[*counter-1])
		time.Sleep(time.Duration(seconds[*counter-1]))
		fmt.Println("worker:", id, "stopping")
		results <- j * 2
	}
}

func main() {

	fmt.Println("Started")
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Reader created")
	stringGot, _ := reader.ReadString('\n')
	fmt.Println("index: ", stringGot)
	var numJobs int
	fmt.Sscanf(stringGot, "%d\n", &numJobs)
	fmt.Println("index converted: ", numJobs)
	timeSleep := make([]float64, numJobs+1)
	var sleepingTimeParsed float64
	for i := 1; i <= numJobs; i++ {
		sleepingTime, _ := reader.ReadString('\n')
		fmt.Sscanf(sleepingTime, "%f\n", &sleepingTimeParsed)
		timeSleep[i] = sleepingTimeParsed
		fmt.Println("sleeping time ", i, ": ", sleepingTime)
	}

	maxWorkersQuant := 10
	if numJobs < maxWorkersQuant {
		maxWorkersQuant = numJobs
	}
	jobs := make(chan int, numJobs)
	results := make(chan int, numJobs)
	fmt.Println("before time.sleep")

	counter := 1
	for w := 1; w <= maxWorkersQuant; w++ {
		go worker(w, jobs, results, timeSleep, &counter)
	}
	fmt.Println("after workers call")

	for j := 1; j <= numJobs; j++ {
		jobs <- j
	}
	close(jobs)

	for a := 1; a <= numJobs; a++ {
		<-results
	}
}
