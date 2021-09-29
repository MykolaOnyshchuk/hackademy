package cipher

import (
	"strings"
)

type Cipher interface {
	Encode(string) string
	Decode(string) string
}

type Ceasar struct{}

func NewCaesar() Cipher {
	return Ceasar{}
}

func (c Ceasar) Encode(s string) string {
	s = format(s)
	cipherArr := []rune(s)
	var newEl rune
	for i, v := range string(s) {
		newEl = v + 3
		cipherArr[i] = changeCharCode(newEl)
	}
	return string(cipherArr)
}

func (c Ceasar) Decode(s string) string {
	s = format(s)
	cipherArr := []rune(s)
	var newEl rune
	for i, v := range string(s) {
		newEl = v - 3
		cipherArr[i] = changeCharCode(newEl)
	}
	return string(cipherArr)
}

func format(s string) string {
	var str []rune
	for i, v := range s {
		if (v >= 65 && v <= 90) || (v >= 97 && v <= 122) {
			str = append(str, v)
		} else {
			i--
		}
	}
	s = strings.ToLower(string(str))
	return s
}
