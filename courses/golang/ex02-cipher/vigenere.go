package cipher

type Vigenere struct {
	shiftStr string
}

func NewVigenere(s string) Cipher {
	if len(s) == 0 {
		return nil
	}
	var allA bool = true
	for _, v := range s {
		if v <= 94 || v >= 123 {
			return nil
		}
		if v != 'a' {
			allA = false
		}
	}

	if allA {
		return nil
	}

	return Vigenere{s}
}

func (c Vigenere) Encode(s string) string {
	s = format(s)
	cipherArr := []rune(s)
	var newEl rune
	for i, v := range string(s) {
		newEl = v + rune(c.shiftStr[i%len(c.shiftStr)]) - 'a'
		cipherArr[i] = changeCharCode(newEl)
	}
	return string(cipherArr)
}

func (c Vigenere) Decode(s string) string {
	s = format(s)
	cipherArr := []rune(s)
	var newEl rune
	for i, v := range string(s) {
		newEl = v - (rune(c.shiftStr[i%len(c.shiftStr)]) - 'a')
		cipherArr[i] = changeCharCode(newEl)
	}
	return string(cipherArr)
}
