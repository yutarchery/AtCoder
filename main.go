package main

import (
	"bufio"
	"os"
)

func main() {
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

}
