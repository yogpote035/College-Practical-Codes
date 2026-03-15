// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract SimpleBank {

    uint private balance;

    // Deposit money
    function deposit(uint amount) public {
        balance += amount;
    }

    // Withdraw money
    function withdraw(uint amount) public {
        require(balance >= amount, "Insufficient balance");
        balance -= amount;
    }

    // Check balance
    function getBalance() public view returns(uint) {
        return balance;
    }
}