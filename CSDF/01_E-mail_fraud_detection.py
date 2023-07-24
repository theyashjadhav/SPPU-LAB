import email

def display_email_headers(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        msg = email.message_from_file(file)

    print("=== Email Headers ===")
    for key, value in msg.items():
        print(f"{key}: {value}\n\n")

if __name__ == "__main__":
    file_path = "Fraud.eml"
    display_email_headers(file_path)
