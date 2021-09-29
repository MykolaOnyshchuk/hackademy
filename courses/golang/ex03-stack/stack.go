package stack

type Stack struct {
	stackArr []int
}

func New() *Stack {
	return &Stack {make([]int,0)}
}

func (stackArr *Stack) Push(v int) {
	stackArr.stackArr = append(stackArr.stackArr, v)
}

func (stackArr *Stack) Pop() (int) {
	l := len(stackArr.stackArr)
	if l == 0 {
		return 0
	}

	res := stackArr.stackArr[l-1]
	stackArr.stackArr = stackArr.stackArr[:l-1]
	return res
}
