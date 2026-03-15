from flask import Flask, jsonify
import datetime

app = Flask(__name__)

class Block:
    def __init__(self, index, data, previous_hash):
        self.index = index
        self.timestamp = str(datetime.datetime.now())
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

        block = Block(len(self.chain) + 1, data, previous_hash)
        self.chain.append(block)

blockchain = Blockchain()

# Add some blocks
blockchain.add_block("First Block")
blockchain.add_block("Second Block")
blockchain.add_block("Third Block")

# Route to display blockchain
@app.route('/blocks', methods=['GET'])
def get_blocks():
    blocks = []
    for block in blockchain.chain:
        blocks.append({
            "index": block.index,
            "timestamp": block.timestamp,
            "data": block.data,
            "previous_hash": block.previous_hash
        })
    return jsonify(blocks)

if __name__ == '__main__':
    app.run(debug=True)


# How to Run

# Install Flask

# pip install flask

# ***** Run program *****

# python app.py

# Open browser

# http://127.0.0.1:5000/blocks
# Example Output (Browser)
# [
#  {
#   "index": 1,
#   "timestamp": "2026-03-14...",
#   "data": "First Block",
#   "previous_hash": "0"
#  },
#  {
#   "index": 2,
#   "timestamp": "2026-03-14...",
#   "data": "Second Block",
#   "previous_hash": "1"
#  }
# ]    