// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Voting {

    mapping(string => uint) private votes;

    // Vote for a candidate
    function vote(string memory candidate) public {
        votes[candidate] += 1;
    }

    // View votes of a candidate
    function getVotes(string memory candidate) public view returns(uint) {
        return votes[candidate];
    }
}