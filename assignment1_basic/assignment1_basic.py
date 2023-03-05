import numpy as np
from string import ascii_lowercase
import matplotlib.pyplot as plt
from functools import wraps
import time
import argparse

#description
parser = argparse.ArgumentParser(description="The program counts the frequency of each letter of the English alphabet in a text")
args = parser.parse_args()

###FUNCTIONS
def clocked(func):
    #wrapper to tell execution time
    @wraps(func)
    def wrapper(*args,**kwargs):
        tstart = time.time_ns()
        result = func(*args,**kwargs)
        exec_time = time.time_ns() - tstart
        print(f"Function {func.__name__} executed in {exec_time/10**9} s")
        return result
    return wrapper

def histogram(letter,occurence):
    #print histogram of frequency
    plt.figure()
    plt.bar(letter,occurence)
    return 0

@clocked
def frequency(filename,plot=False,allinfo=False):
    #define lowercase alphabet, open file and read it
    alphabet = list(ascii_lowercase)
    with open(filename) as file:
        text = file.read()
        if(allinfo):    text_lines = file.readlines()

    #count occurence of letters
    text = text.casefold()
    freq = []
    for i,_ in enumerate(alphabet):
        freq.append(text.count(alphabet[i]))

    print(alphabet)
    print(freq)

    if(allinfo):
        #find all characters
        characts = sum(freq)
        #number of lines
        separator = "\n"
        lines = text.count(separator)
        multi_lines=0
        while(text.count(separator)!=0):
            separator += separator
            multi_lines+= text.count(separator)
        lines -= multi_lines

        #find all words
        space_char = " "
        spaces = text.count(space_char) + lines
        multi_spaces=0
        while(text.count(space_char)!=0):
            space_char += space_char
            multi_spaces += text.count(space_char)
        spaces -= multi_spaces

        print(f"Number of characters: {characts}")
        print(f"Number of words: {spaces}")
        print(f"Number of lines: {lines}")


    if(plot):   histogram(alphabet,freq)

    return plt.show()

###MAIN
path = input("Pass a path to a txt file to analyze:")

plot = input("Do you want to plot the results? (Y/N)")

if(plot=="Y"):
    plot = True
elif(plot=="N"):
    plot = False
else:
    raise ValueError

info = input("Do you want to print all the statistics? (Y/N):")

if(info=="Y"):
    info = True
elif(plot=="N"):
    info = False
else:
    raise ValueError

frequency(path,plot,info)