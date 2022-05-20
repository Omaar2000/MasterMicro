#                                                   بسم الله الرحمن الرحيم      

#from logging import exception
from tkinter import *
from tkinter import messagebox
import numpy as np
import matplotlib.pyplot as plt
#from pyparsing import col
import compiler

Window = Tk()
Window.title("Function Plotter")
Window.configure(bg="#141414")

e = Entry(Window , width = 30, bg= "#242424",fg = "#00ff77", )
minVal = Entry(Window , width = 30, bg= "#242424",fg = "#00ff77")
maxVal = Entry(Window , width = 30, bg= "#242424",fg = "#00ff77")
minVal.grid(row = 3, column=0, columnspan=4, padx= 10, pady=10)
maxVal.grid(row = 5, column=0, columnspan=4, padx= 10, pady=10)
e.grid(row = 1, column=0, columnspan=4, padx= 10, pady=10)

label1 = Label(Window, text = "Enter the equation ", bg= "#141414",fg = "#00ff77")
label2 = Label(Window, text = "Enter minimum value of x ", bg= "#141414",fg = "#00ff77")
label3 = Label(Window, text = "Enter maximum value of x ", bg= "#141414",fg = "#00ff77")
#labelnote = Label(Window, text = "*IMPORTANT NOTES* ",bg= "red", fg = "white", font="Times 16 bold")
labelMult = Label(Window, text = "Use the symbol * to multiplication " ,bg= "#141414",fg ="#00ff77", font="Times 11 bold")
labelDiv = Label(Window, text = "Use the symbol / for division " ,bg= "#141414",fg ="#00ff77", font="Times 11 bold")
labelPow = Label(Window, text = "Use the symbol ^ for power" ,bg= "#141414",fg ="#00ff77", font="Times 11 bold")
label1.grid (row = 0, column = 0)
label2.grid (row = 2, column = 0)
label3.grid (row = 4, column = 0)
#labelnote.grid (row = 6, column = 0)
labelMult.grid (row = 7, column = 0)
labelDiv.grid (row = 8, column = 0)
labelPow.grid (row = 9, column = 0)

def popup (errorName):
    messagebox.showerror("Error", errorName )

def button_PLOT():
    minimumVal=0
    maximumVal=0
    a = ""
    try:
        minimumVal=int(minVal.get())
        maximumVal=int(maxVal.get())
        if (maximumVal >minimumVal):
            x = np.array(range(minimumVal,maximumVal))
            try:
                input = e.get().replace("^", "**")
                if input !="" :    
                    Equation = input.lower()
                    if "x" not in input:
                        Equation = f"{input}+0*x"
                    y = eval(Equation)
                    plt.plot(x,y)
                    plt.show()
                else :
                    a= "invalid equation!"
                    popup(a)        
            except Exception:
                a= "invalid equation!" 
                popup(a)
        else:
            a = "invalid range, maximum value should be greater than minimum one!"
            popup(a)
    except Exception:
         a = "Enter valid limits please, They should be numbers!"
         popup(a)
    return a     

    
def on_enter(e):
        button_graph['background']="#141414"
        button_graph['foreground']="#00ff77"    

def on_leave(e):
        button_graph['background']="#00ff77" 
        button_graph['foreground']="#141414"

# Defining Buttons
button_graph = Button(Window, text="Plot",fg= "#141414",bg ="#00ff77",activeforeground= "#00ff77",
activebackground= "#141414",padx=20, pady= 10, command = button_PLOT)
# Putting them  on the screen
button_graph.grid(row = 11, column =0 )

button_graph.bind("<Enter>", on_enter)
button_graph.bind("<Leave>", on_leave)


if __name__ == '__main__' :
    Window.mainloop()

 #                                                    ^_^ والحمد لله رب العالمين      
