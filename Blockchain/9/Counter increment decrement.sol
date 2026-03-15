// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Counter {

    uint private count;

    // Increment counter
    function increment() public {
        count += 1;
    }

    // Decrement counter
    function decrement() public {
        require(count > 0, "Counter cannot be negative");
        count -= 1;
    }

    // View counter value
    function getCount() public view returns(uint) {
        return count;
    }
}