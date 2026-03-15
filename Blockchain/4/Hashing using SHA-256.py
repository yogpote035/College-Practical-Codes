import hashlib

# Input message
data = input("Enter text to hash: ")

# Create SHA-256 hash
hash_value = hashlib.sha256(data.encode())

# Display hash
print("SHA-256 Hash:", hash_value.hexdigest())