// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StringStorage {

    string public text;

    // Update the string
    function updateText(string memory _text) public {
        text = _text;
    }
}