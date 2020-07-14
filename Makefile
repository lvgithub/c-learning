# x:=foo
# y:=$(x)b
# x:=new
# test:
# 	@echo "y=>$(y)"
# 	@echo "x=>$(x)"

x:=foo
y=$(x)b
x:=new
test:
	@echo "y=>$(y)"
	@echo "x=>$(x)"