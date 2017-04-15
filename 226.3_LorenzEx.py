def g(y):
	if y > 0:
		return (3.0/2)*y**(2.0/3) - 0.5
	elif y < 0:
		return 0.5 - (3.0/2)*(-y)**(2.0/3)

print( g(1.0/8) )

print( g( g(1.0/8) ) )
