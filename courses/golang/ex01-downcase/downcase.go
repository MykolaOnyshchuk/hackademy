package downcase

func Downcase (initial string) (string, error) {
	result := ""
	for i := 0; i < len([]rune(initial)); i++ {
		if []rune(initial)[i] >= 65 && []rune(initial)[i] <= 90 {
			result += string(initial[i] + 32)
		} else {
			result += string(initial[i])
		}
	}
	return result, nil
}
