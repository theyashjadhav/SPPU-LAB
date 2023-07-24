from email import message_from_file
from email.parser import HeaderParser

f = open("Research Paper.eml")

message = message_from_file(f)

# print(message.as_string())

parser = HeaderParser()

headers = parser.parsestr(message.as_string())

print("Headers: ")

for header in headers.items():
    print(header)


print("\nSPF and DKIM are-\n")

print(headers.items()[5][-1])