pragma solidity ^0.8.0;

contract TextStorage {

    string private text;

    // Store or modify text
    function setText(string memory _text) public {
        text = _text;
    }

    // View stored text
    function getText() public view returns(string memory){
        return text;
    }
}