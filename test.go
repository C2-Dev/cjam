package main

import (
	"fmt"
	"sort"
)

func main() {
	primes := []int{1,9,3,8,5,6}
	sort.Ints(primes)
	fmt.Println(primes)
}