import random
import string
import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk
from captcha.image import ImageCaptcha

def get_random_word(length):
    letters = string.ascii_lowercase + string.ascii_uppercase
    random_word = ''.join(random.choice(letters) for _ in range(length))
    return random_word

def check_text_input(expected_text):
    user_input = text_input.get()

    if user_input == expected_text:
        result_label.config(text="Text matched!", foreground="green")
        print('Result : Text matched!')
    else:
        result_label.config(text="Text not matched!", foreground="red")
        print('Result : Text not matched!')

def reset_captcha():
    global captcha_text, photo

    captcha_text = get_random_word(5)
    data = Cimage.generate(captcha_text)
    print('captcha text is :', captcha_text)
    Cimage.write(captcha_text, 'CAPTCHA.png')

    # Load the new image and update the display
    image_path = "D:\EDUCATION\SPPU-LAB\CSDF\CAPTCHA.png"
    image = Image.open(image_path)
    image.thumbnail((300, 300))
    photo = ImageTk.PhotoImage(image)
    image_label.config(image=photo)

    # Clear the text input and result label
    text_input.delete(0, tk.END)
    result_label.config(text="", foreground="black")

# Create the main application window
root = tk.Tk()
root.title("Image and Text Input")
root.geometry("400x300")  # Set window size

# Initialize captcha text and display it
Cimage = ImageCaptcha(width=280, height=90)
captcha_text = get_random_word(5)
data = Cimage.generate(captcha_text)
print('captcha text is :', captcha_text)
Cimage.write(captcha_text, 'CAPTCHA.png')

# Load the fixed image
image_path = "D:\EDUCATION\SPPU-LAB\CSDF\CAPTCHA.png"
image = Image.open(image_path)
image.thumbnail((300, 300))
photo = ImageTk.PhotoImage(image)

# Create and place widgets
frame = ttk.Frame(root)
frame.pack(expand=True)

image_label = ttk.Label(frame, image=photo)
image_label.pack(pady=10)

text_input = ttk.Entry(frame, font=("Arial", 14))
text_input.pack(pady=10)

submit_button = ttk.Button(frame, text="Submit", command=lambda: check_text_input(captcha_text))
submit_button.pack(pady=5)

reset_button = ttk.Button(frame, text="Reset", command=reset_captcha)
reset_button.pack(pady=5)

result_label = ttk.Label(frame, text="", font=("Arial", 12))
result_label.pack(pady=10)

# Run the application
root.mainloop()
