CFLAGS := -std=c99 -c

library: compile
	@ar -rcs libft.a $(wildcard *.o)
	@echo "libft.a"

compile:
	@$(CC) $< $(CFLAGS) $(wildcard *.c)
	@echo "Compilation complete"
