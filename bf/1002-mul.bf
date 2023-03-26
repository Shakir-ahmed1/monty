
,		# get input in c0 
>++++ ++++		# add 8 to c1
[<---- -- > -]		# subtract 6 from c0 and subtract 1 from c1 to multiply 6 by 8 and subtract 48
,			# get input in c1 (since c1 became zero)
>++++ ++++		# add 8 to c2
[<---- -- > -]		# subtract 6 from c1 and subtract 1 from c2 to multiply 6 by 8 and subtract 48
<
[
<			# c0
((( set c0 = c2
[>> + > + <<< -]	# moves value of c0 to c2 and c3
>>>			# c3
[<<< + >>> -]		# moves value of c3 to c0
<<<			# c0
)))

>>			# c2
[>> + << -]		# move the value of c2 to c4
<<			# c0
>-
]
>>>>

++++ ++++		# set c2 to 8
[<++++ ++ > -]		# add 6 from c1 and subtract 1 from c2 to multiply 6 by 8 and add 48
<.			# print the result in c1



