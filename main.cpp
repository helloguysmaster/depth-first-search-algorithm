#include <vector>
#include <cstdio>

struct Node
{
    int id;
    bool visited;
    std::vector<Node*> connected;
};

const int nodeNumber = 13;
Node nodes[nodeNumber];

void DFS(int nodeIndex)
{
    if (nodes[nodeIndex].visited)
    {
        printf("backtracked: %d\n", nodeIndex);
        return;
    }
    printf("traveled: %d\n", nodeIndex);
    nodes[nodeIndex].visited = true;
    for (int i = 0; i < nodes[nodeIndex].connected.size(); i++)
    {
        DFS(nodes[nodeIndex].connected[i]->id);
    }
}

int main(void)
{
    nodes[0] = {0};
    nodes[0].id = 0;
    nodes[1] = {0};
    nodes[1].id = 1;
    nodes[2] = {0};
    nodes[2].id = 2;
    nodes[3] = {0};
    nodes[3].id = 3;
    nodes[4] = {0};
    nodes[4].id = 4;
    nodes[5] = {0};
    nodes[5].id = 5;
    nodes[6] = {0};
    nodes[6].id = 6;
    nodes[7] = {0};
    nodes[7].id = 7;
    nodes[8] = {0};
    nodes[8].id = 8;
    nodes[9] = {0};
    nodes[9].id = 9;
    nodes[10] = {0};
    nodes[10].id = 10;
    nodes[11] = {0};
    nodes[11].id = 11;
    nodes[12] = {0};
    nodes[12].id = 12;
    
    nodes[0].connected.push_back(&nodes[1]);
    nodes[0].connected.push_back(&nodes[9]);
    
    nodes[1].connected.push_back(&nodes[0]);
    nodes[1].connected.push_back(&nodes[8]);
    
    nodes[9].connected.push_back(&nodes[0]);
    nodes[9].connected.push_back(&nodes[8]);
    
    nodes[8].connected.push_back(&nodes[1]);
    nodes[8].connected.push_back(&nodes[7]);
    nodes[8].connected.push_back(&nodes[9]);
    
    nodes[7].connected.push_back(&nodes[3]);
    nodes[7].connected.push_back(&nodes[6]);
    nodes[7].connected.push_back(&nodes[8]);
    nodes[7].connected.push_back(&nodes[10]);
    nodes[7].connected.push_back(&nodes[11]);
    
    nodes[10].connected.push_back(&nodes[7]);
    nodes[10].connected.push_back(&nodes[11]);
    
    nodes[11].connected.push_back(&nodes[7]);
    nodes[11].connected.push_back(&nodes[10]);
    
    nodes[3].connected.push_back(&nodes[2]);
    nodes[3].connected.push_back(&nodes[4]);
    nodes[3].connected.push_back(&nodes[5]);
    
    nodes[2].connected.push_back(&nodes[3]);
    
    nodes[4].connected.push_back(&nodes[3]);
    
    nodes[5].connected.push_back(&nodes[3]);
    nodes[5].connected.push_back(&nodes[6]);
    
    nodes[6].connected.push_back(&nodes[5]);
    nodes[6].connected.push_back(&nodes[7]);
    
    DFS(0);

    return 0;
}
