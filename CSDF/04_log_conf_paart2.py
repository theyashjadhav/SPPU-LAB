import logging


def word_count(myfile):
    logging.basicConfig(level=logging.DEBUG,
                        filename=myfile, format='%(asctime)s %(levelname)s:% (message)s')
    try:
        with open(myfile, 'r') as f:
            file_data = f.read()
            words = file_data.split()
            num_words = len(words)
            print(f"this file has {num_words} words")
        return num_words
    except OSError as e:
        logging.error("error reading the file")


file_name = 'D:\\EDUCATION\\SPPU-LAB\\CSDF\\temp.log'
word_count(file_name)
