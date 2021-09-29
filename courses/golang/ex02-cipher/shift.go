package cipher

type Shift struct {
	shift int
}

func NewShift(i int) Cipher {
	if i < -25 || i > 25 || i == 0 {
		return nil
	}
	return Shift{i}
}

func (c Shift) Encode(s string) string {
	s = format(s)
	cipherArr := []rune(s)
	var newEl rune
	for i, v := range string(s) {
		newEl = v + rune(c.shift)
		cipherArr[i] = changeCharCode(newEl)
	}
	return string(cipherArr)
}

func (c Shift) Decode(s string) string {
	s = format(s)
	cipherArr := []rune(s)
	var newEl rune
	for i, v := range string(s) {
		newEl = v - rune(c.shift)
		cipherArr[i] = changeCharCode(newEl)
	}
	return string(cipherArr)
}

func changeCharCode(r rune) rune {
	if r >= 97 && r <= 122 {
		return r
	} else if r >= 71 && r <= 96 {
		return 122 - (96 - r)
	} else if r >= 123 && r <= 148 {
		return 97 + r - 123
	}
	return 0
}
