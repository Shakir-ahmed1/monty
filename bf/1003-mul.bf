
,>,>++++ ++++[<---- -- < ---- -- >> -]< # c0=input c1=input $c1
[<[>> + > + <<< -]>>>[<<< + >>> -]<<<>>[>> + << -]<<>-]>>> multiplies c0 and c1 place the product in c4 $c4
<<<< [-] >>>> [ <<<< + >>>> -]<<<< # resets c0 to 0 and moves the value of c4 to c0
# c0 = multiplied number$c0 every cell other than c0 is set to 0 at this point


# the code bellow stores the tenth value of the number at c6 and the once number at c1
[-
        >>>> [-] ++++ ++++ ++ <<<< # c4 = 10 c4 is always set to 10 at this point
        >>>>> [-] + <<<<< # c5 = 1 c5 is always set to 1 at this point
        >+	# c1 is incremented by 1 in each loop but is reset to 0 every time reaches 10
        >[-]<[> + > + << -]>>[ << + >> -]< copies c1 to c2 and point to c2 # requires a free c3 to operate i
        [ - >> - <<] # compares c2 and c4 if equal (c2=c4=10) c4 becomes 0
        >>[[-] > - <]<<		# if c4 is 0 this line is not excuted (if this line is executed it sets c5 to 0 making) NOTE: doesn't loop
        >>>[ >+< <<<< [-] >>>> -]<<< # if the above line is not excuted this line is excuted because c5 is 1% NOTE: doesn't loop
        << # $c0

]
>>>>>> # $c6
>++++ ++++[<++++ ++ > -]<. # print the number in c6 using ascii
<<<<< # $c1
>++++ ++++[<++++ ++ > -]<. # print the number in c1 using ascii 
[-] ++++ ++++ ++.


c0 = multiplied number
c1 = temporary counter until 10, it is reseted if it is 10
c2 = a copy of c1 that can be used for comparesion
c3 = cach for copying c1 to c2
c4 = always 10 used for comparision
c5 = always 1 used for conditional if statement
c6 = the tenth of the number



