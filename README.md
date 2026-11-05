# Impossible Interview Question

Solving the unsolvable.

## The Question In Question: Inverting A Binary Tree

Binary trees are rather tricky. They're completely normal and standard tree data structures that come with an unfortunate restriction; no node can have more than two children (very sad.)

Inverting a binary tree is even more imposing. When a node has two children, you swap them... that's it.

## Pseudocode

```
function invert(root) {
    dynamic_array = empty;

    dynamic_array.append(root);

    while dynamic_array.length > 0 {
        node = dynamic_array.pop();

        if node.left_child and node.right_child {
            node.swapChildren();
            dynamic_array.append(node.left_child);
            dynamic_array.append(node.right_child);
        } else if node.left_child {
            // If there's only one child, it's the left child.
            dynamic_array.append(node.left_child);
        }
    }
}
```

18 lines, 512 characters, I only hope that they don't start publishing books this long.

## Background

I saw [a tweet](https://x.com/Jonathan_Blow/status/2117003832337338631) from Jonathan Blow about binary trees and got curious.
I had heard about binary trees but never looked into them (not everything makes me so curious.)
Apparently, a "binary tree" is just a slightly more special tree, which is pretty simple.
Then, I looked up what "inverting" a binary tree meant, another term I had heard but never looked into.
Confusingly, it seemed to be an extremely basic operation where you just swap the children of every node.

In conclusion, I don't understand why anybody ever talks about this, it seems to be very basic.
It's not a good interview question to gauge whether or not someone is an elite level programmer who belongs in the hall of fame (probably.)
It IS a good interview question to see if a person even belongs in the interview though, because it's a very simple problem and hopefully, as a programmer, you can at least solve very simple problems.

<sub>People that think this is an unfair interview question are probably a byproduct of programming becoming more mainstream as a (maybe previously...) easy money job.</sub>
