*-----------------------------------------------------------
* Title      : Assembly Subroutines
* Written by : Justin Delisi
* Date       : 11/12/18
* Description: Demonstrate Subroutines in Assembly Language
*-----------------------------------------------------------
    ORG    $1000
START:                  
    BSR FIRST           *load first subroutine
    BSR SECOND          *load second subroutine
    BSR THIRD           *load third subroutine
    
    

    SIMHALT             ; halt simulator
CR      EQU $0D
LF      EQU $0A
ARRAY   DS.W 10
ODDEVEN DS.W 10
MSG1 DC.B 'Input the array of size 10 hitting enter after each input: ',0
MSG2 DC.B 'Enter 1 for odd or 2 for even: ',0
MSG3 DC.B 'Invalid input, please input 1 or 2',CR,LF,0
SPACE DC.B ' ',0
DISODD DC.B 'The odd numbers are: ',0
DISEVEN DC.B 'The even numbers are: ',0
INORDER DC.B 'The numbers in ascending order are: ',0
CRLF    DC.B CR,LF,0

    STOP #$2700
FIRST 
    MOVE #0,D4           *loop counter
    MOVE.B #14,D0
    LEA MSG1,A1
    TRAP #15
    LEA ARRAY,A2        *load the array
LOAD 
    
    MOVE.B #4,D0        *input from keyboard
    TRAP #15
    MOVE.W D1,(A2)+      *insert into ith entry in array
    ADD #1,D4
    CMP #10,D4
    BNE LOAD
    
TRY MOVE.B #14,D0       *display message 2
    LEA MSG2,A1
    TRAP #15
    
    MOVE.B #4,D0        *input from keyboard
    TRAP #15
    
    CMP #1, D1          *compare to for next subroutine
    BEQ EXIT
    CMP #2, D1
    BEQ EXIT
    
    MOVE.B #14,D0
    LEA MSG3,A1
    TRAP #15
    BRA TRY

EXIT RTS 

********************************************************************
   
SECOND 
    LEA ARRAY,A2       *loads the first element of array
    LEA ODDEVEN,A3    *load second array for odd or even
    MOVE.B #0,D3 *counter (i)
    MOVE.B #0,D4 *counter (j)
    CMP #1,D1
    BNE EVEN
    
ODD 
    CLR D2
    MOVE.W (A2)+,D2   *move ith element into d2
    MOVE.L D2,D5        *move to D5 to perform mod 
    DIVU #2,D5      *mod to see if it's odd
    SWAP D5
    CMP #0,D5
    BEQ NEXT
    
ADDODD 
    MOVE.W D2,(A3)+   *if odd add to odd array
    ADD #1,D4

NEXT
    ADD #1,D3
    CMP #10,D3
    BNE ODD
    
    LEA DISODD,A1
    MOVE.B #14,D0
    TRAP #15
    BRA DISPLAY
    
EVEN 
    CLR D2
    MOVE (A2)+,D2    *move ith element into d2
    MOVE.L D2,D5
    DIVU #2,D5      *mod to see if it's even
    SWAP D5
    CMP #0,D5
    BNE NEXT1   
 
ADDEVEN 
    MOVE.W D2,(A3)+   *if even add to oddeven array
    ADD #1,D4

NEXT1
    ADD #1,D3
    CMP #10,D3
    BNE EVEN
    
    LEA DISEVEN,A1
    MOVE.B #14,D0
    TRAP #15
    
DISPLAY 
    LEA ODDEVEN,A3
    MOVE.L D4,D7        *save length of array in D6 for THIRD
LOOP 
    MOVE.W (A3)+,D1    *display the odd or even numbers
    MOVE.B #3,D0
    TRAP #15
    
    LEA SPACE,A1        *prints a space between numbers
    MOVE.B #14,D0
    TRAP #15
    
    SUB #1,D4
    CMP #0,D4
    BNE LOOP         *branch while counter is nonnegative
    RTS 

*******************************************************************   

THIRD   
    
    LEA ODDEVEN,A3      *load the oddeven array
    CLR D2              *i
    CLR D3              *j
    CLR D4              *boolean for swapped
    CLR D5              *holds A[j]
    CLR D6              *holds A[j+1]
    MOVE.W D7,D0        *holds length-i-1
    SUB #1,D7           *length of array (from SECOND) -1
    
    

FOR1
    MOVE.W #0,D3  
    MOVE.W #0,D4        *swapped = false
    LEA ODDEVEN,A3
    SUB #1,D0
FOR2
    MOVE (A3)+,D5       *D5 = A[j]
    MOVE (A3),D6        *D6 = A[j+1]
    SUB #2,A3
    
    CMP D6,D5
    BGT IF
    BRA ELSE

IF  MOVE D6,(A3)+
    MOVE D5,(A3)        *swap them
    MOVE #1,D4          *swapped = true
    BRA NEXTENTRY

ELSE
    ADD #2,A3

NEXTENTRY 
    ADD #1,D3           *j++
    CMP D0,D3
    BLT FOR2
    
    CMP #0,D4           *if swapped == false break
    BEQ FINAL
    
    ADD #1,D2           *i++
    CMP D7,D2
    BLT FOR1

FINAL
    LEA ODDEVEN,A3
    ADD #1,D7           *gets D7 back to length of array
    
    LEA CRLF,A1
    MOVE.W #14,D0
    TRAP #15
    LEA INORDER,A1
    MOVE.W #14, D0
    TRAP #15
LOOP1
    MOVE.W (A3)+,D1    *display the odd or even numbers
    MOVE.B #3,D0
    TRAP #15
    
    LEA SPACE,A1        *prints a space between numbers
    MOVE.B #14,D0
    TRAP #15
    
    SUB #1,D7
    CMP #0,D7
    BNE LOOP1         *branch while counter is nonnegative
    RTS 

 
    
    END    START        ; last line of source





*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
