// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Product {

    string public productName;
    uint public price;

    // Store product information
    function setProduct(string memory _productName, uint _price) public {
        productName = _productName;
        price = _price;
    }
}