import datetime

class Block:
    def __init__(self, index, data, previous_hash):
        self.index = index
        self.timestamp = datetime.datetime.now()
        self.data = data
        self.previous_hash = previous_hash

class Blockchain:
    def __init__(self):
        self.chain = []

    def add_block(self, data):
        if len(self.chain) == 0:
            previous_hash = "0"
        else:
            previous_hash = str(self.chain[-1].index)

        new_block = Block(len(self.chain) + 1, data, previous_hash)
        self.chain.append(new_block)

    def display(self):
        for block in self.chain:
            print("Index:", block.index)
            print("Timestamp:", block.timestamp)
            print("Data:", block.data)
            print("Previous Hash:", block.previous_hash)
            print("---------------------------")

# Create blockchain
bc = Blockchain()

# Add blocks
bc.add_block("First Block")
bc.add_block("Second Block")
bc.add_block("Third Block")

# Display blockchain
bc.display()