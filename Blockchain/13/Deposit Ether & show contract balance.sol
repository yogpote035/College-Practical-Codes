// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract EtherBank {

    // Function to deposit Ether
    function deposit() public payable {
        
    }

    // Function to display contract balance
    function getBalance() public view returns(uint) {
        return address(this).balance;
    }
}