import datetime

class Block:
    def __init__(self, index, data, previous_hash):
        self.index = index
        self.timestamp = datetime.datetime.now()
        self.data = data
        self.previous_hash = previous_hash

    def display(self):
        print("Index:", self.index)
        print("Timestamp:", self.timestamp)
        print("Data:", self.data)
        print("Previous Hash:", self.previous_hash)

# Create blocks
block1 = Block(1, "First Block", "0")
block2 = Block(2, "Second Block", "abc123")

# Display block details
block1.display()
print("---------------")
block2.display()