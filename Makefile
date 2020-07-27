# x:=foo
# y:=$(x)b
# x:=new
# test:
# 	@echo "y=>$(y)"
# 	@echo "x=>$(x)"

echo/foo.o: src/hello.c
	@#echo/foo.o
	@echo $@

	@#echo
	@echo $(@D)

	@#foo.os
	@echo $(@F)

	@echo $(<F)
	@echo $(<D)


