import os.path
import matplotlib.pyplot as plt
import PIL
import PIL.ImageDraw
import numpy as np

'''Read the image data'''
def open_file(filename):
    directory = os.path.dirname(os.path.abspath(__file__)) 
    filepath = os.path.join(directory, filename)
    img = plt.imread(filepath)
    return img
    
'''Show the image data'''
def show_image():
    fig, ax = plt.subplots(1, 3)  #creates 1 by 2 array
    ax[0].imshow(original_image, interpolation='none')  #fills first column with original image
    ax[1].imshow(changed_image, interpolation='none')   #fills second column with changed image
    ax[2].imshow(final,interpolation='none')         #fills third column with PIL image
    fig.show()

'''changes colors of the image pixel by pixel'''
def change_color(filename):
    height = len(filename)
    width = len(filename[0])
    for r in range(height):
        for c in range(width):
            if sum(filename[r][c])>700: # changes whitish to black
                filename[r][c]=[0,0,0] 
            elif sum(filename[r][c])<100: # changes blackish to white
                filename[r][c]=[255,255,255] 
            elif filename[r][c][0]>194: # changes reddish colors to magenta
                filename[r][c]=[255,0,255] 
            elif filename[r][c][1]>150: # changes goldish color to silver
                filename[r][c]=[204,204,204] 
    return filename

'''changes image using the Python Image Library (PIL)'''
def pil_adjust(my_image):
    thick = my_image.size[0]         #set the width to the width of the image
    tall = my_image.size[1]          #set the height to the width of the image
    
    my_mask = PIL.Image.new('RGBA', (thick, tall), (0,0,0,0))        #takes imported image and makes it a PIL image
    drawing_layer = PIL.ImageDraw.Draw(my_mask)                      #makes a drawing layer of image for the mask
    drawing_layer.ellipse((176,92,1180,679), fill=(0,255,0,255))     #draws an ellipse on the mask with transparent background
    
    result = PIL.Image.new('RGBA', (thick, tall))                    #initializes the final image
    result.paste(my_image, (0,0), mask=my_mask)                      #puts the mask and image together
    return result


original_image = open_file('49ers.jpg')
changed_image = open_file('49ers.jpg')
to_convert = change_color(changed_image)
my_image = PIL.Image.fromarray(to_convert)
final = pil_adjust(my_image)
final.save("C:/Users/jorda/Desktop/CSP Training/1.4.7 Stuff/finalpicture.gif")

show_image()

