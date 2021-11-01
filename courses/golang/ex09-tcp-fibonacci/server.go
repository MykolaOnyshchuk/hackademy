package main

import (
	"encoding/json"
	"net"
)
import "fmt"
import "bufio"

func main() {

	fmt.Println("Launching server...")

	ln, _ := net.Listen("tcp", ":8081")

	conn, _ := ln.Accept()

	for {
		message, _ := bufio.NewReader(conn).ReadString('\n')
		fmt.Print("Message Received:", string(message))

		var ind int
		fmt.Sscanf(message, "%d\n", &ind)
		res := fibonacciRec(ind)
		mapA := map[string]int{"result": res}
		mapB, _ := json.Marshal(mapA)

		conn.Write([]byte(string(mapB) + "\n"))
		fmt.Print("Message Sent:", mapA)
	}
}

func fibonacciRec(n int) int {
	if n <= 1 {
		return n
	}
	return fibonacciRec(n-1) + fibonacciRec(n-2)
}
