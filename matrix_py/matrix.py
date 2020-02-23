import numpy as np

def backnum(msg):
    """
    This function is for geting number from user and checking that is Number or String and return the True number
    """
    num = 0
    while True:
        num = input(msg)
        # checking the input user is integer or string with .isdigit()
        if num.isdigit():
            return int(num)
            break
        else:
            print("Your input is not Digit please try again...") 
        

def start():
    """
    Start the main function of file
    """
    # getting rows and columns from user with backnum function 
    x = backnum("How many rows ? ")
    y = backnum("How many columns ? ")

    # get the value from user for anyelement of matrix and append to elements list
    elements = []
    for i in range(x*y):
        element = backnum(f"{i+1} Element = ")
        elements.append(element)
   
    # create the two dimensioal matrix with numpy.array and with x row and y columns and elemets list 
    matrix = np.array(elements).reshape(x, y)

    print(matrix)

if __name__ == "__main__":
    start()
