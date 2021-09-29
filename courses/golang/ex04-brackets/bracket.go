package brackets

func Bracket (s string) (bool, error) {
	BracketList := New()
	var lastEl int
	var diff int
	pushed := false
	for i := 0; i < len([]rune(s)); i++ {
		if string([]rune(s)[i]) == "{" || string([]rune(s)[i]) == "[" || string([]rune(s)[i]) == "(" {
			BracketList.Push(int([]rune(s)[i]))
			pushed = true
		}
		if string([]rune(s)[i]) == "}" || string([]rune(s)[i]) == "]" || string([]rune(s)[i]) == ")" {
			lastEl = BracketList.Pop()
			switch string([]rune(s)[i]) {
			case "]":
				diff = 2
			case "}":
				diff = 2
			case ")":
				diff = 1
			}
			if lastEl != int([]rune(s)[i]) - diff {
				return false, nil
			}
		}
	}
	if left := BracketList.Pop(); left != 0 && pushed == true {
		return false, nil
	}
	return true, nil
}
