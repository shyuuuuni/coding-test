function solve(nodeList) {
    const node = nodeList[0];
    if (!node) {
        return null;
    }

    const lower = nodeList.filter((n) => {
        return n.location < node.location;
    });
    const greater = nodeList.filter((n) => {
        return node.location < n.location;
    });

    node.children.left = solve(lower);
    node.children.right = solve(greater);

    return node;
}

function preorder(nodeList) {
    const output = [];
    
    function move(node) {
        if (!node) {
            return;
        }
        output.push(node.index);
        move(node.children.left);
        move(node.children.right);
    }
    move(nodeList[0]);
    
    return output
}
function postorder(nodeList) {
    const output = [];
    
    function move(node) {
        if (!node) {
            return;
        }
        move(node.children.left);
        move(node.children.right);
        output.push(node.index);
    }
    move(nodeList[0]);
    
    return output;
}

function solution(nodeinfo) {
    const nodes = nodeinfo.map((info, i) => {
        return {
            level: info[1],
            location: info[0],
            index: i+1,
            parent: null,
            children: {
                left: null,
                right: null
            }
        };
    });
    nodes.sort((a,b) => {
        if (a.level !== b.level) {
            return b.level - a.level;
        }
        return a.location - b.location;
    });
    const levels = Array.from(new Set(nodes.map(({ level }) => level)));
    const root = nodes[0];
    
    solve(nodes);
    
    return [preorder(nodes), postorder(nodes)];
}