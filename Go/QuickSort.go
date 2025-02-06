package main

import "fmt"

func Partition(vec []int, start int, end int) int {
	pivot := vec[end-1]

	i := start - 1
	for j := start; j < end; j++ {
		if vec[j] < pivot {
			i++
			vec[j], vec[i] = vec[i], vec[j]
		}
	}
	i++
	vec[i], vec[end-1] = vec[end-1], vec[i]
	return i
}

func SortPartition(vec []int, start int, end int) {
	if end-start <= 1 {
		return
	}

	pi := Partition(vec, start, end)

	SortPartition(vec, start, pi)
	SortPartition(vec, pi+1, end)
}

func QuickSort(arr []int) {
	SortPartition(arr, 0, len(arr))
}

func main() {
	for {
		fmt.Print("Number of elements: ")
		count := 0
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := make([]int, count)
		fmt.Print("The array to be sorted: ")
		for i := 0; i < count; i++ {
			fmt.Scan(&vec[i])
		}

		QuickSort(vec)
		fmt.Print("The sorted array: ")
		fmt.Println(vec)
	}
}
