# Review_Mastering the game of Go with deep neural networks and tree search

## Introduction
Alphago는 그동안 불가능의 영역이라 여겨졌던 바둑을 정복하면서 대중에게는 인공지능, 특히 기계학습을 인지시켰고, 연구자들에게는 기계학습 활용의 방벌론을 제시했다. 
인공지능을 실현함에 있어 인류는 다양한 방법을 시도했다. 하지만 재정상의 이유 또는 만족할만한 정확성이나 정밀성을 보장하지 않는다는 이유로 인해 기계학습만이 인공지능의 구현 방법으로써 살아남았고, 현재는 거의 인공지능 = 기계학습이라고 봐도 무방하다.

Alphago는 바둑이라는 제한된 환경 하에 있는 인공지능이다. 인공지능을 구현함에 있어 환경은 매우 중요하다. 환경은 학습을 시킬 변수를 결정짓고, 학습의 방향도 제시한다. 그렇기에 loss function의 구현이 가능하고, 학습이 가능한 것이다.
그렇게 3^361이상의 무지막지한 경우의 수를 포함한 환경에서 Alphago는 suboptimal solution을 학습을 통해 도출해냈고, 판 후이 2단과의 대국을 전승으로 이끌어나가면서 인간을 뛰어넘었음을 입증했다.

나는 Alphago에게 주어진 환경과, 그 환경을 어떻게 활용했는지에 대해 고찰했다.

## Conclusion
Alphago에 주어진 환경은 361칸의 바둑판이다. Extended data table 2를 보면, Neural networks에 input으로 들어가는 변수들을 볼 수 있다. 이를 요약하면 다음과 같다.
###
    1. 게임판 칸의 기본 정보(흰색 or 검은색 or 빈 칸)
    2. 턴 수
    3. Libertiy(인접한 빈 칸)의 수
    4. 따낸 돌 수, 따인 돌 수
    5. 착수 정보
이 중, 4번 5번 정보는 바둑의 규칙이라는 환경에 초점을 둔 정보다.

해당 input을 보고, 가장 먼저 유추할 수 있는 부분은 Alphago의 학습환경이 이산적으로 표현이 가능하다는 것이다. 따라서 Alphago는 특정 timestep과, field 정보를 하나의 state로 규정하는 것이 가능했다. 각각의 state는 전후관계가 있었고, 이를 timestep = depth인 tree형태로 나타낼 수 있었다. 즉, solution의 탐색을 tree search와 동치였으며, Alphago는 Monte-Carlo tree search, MCTS를 통해 탐색이 가능한 것이다. 

그 다음으로, 바둑이라는 게임 환경에서 플레이어는 모든 정보를 알 수 있다는 것이다. 환경인지에서 확률을 배제할 수 있는 특징으로 인해, Alphago의 state tree는 확률요소를 포함하지 않았고, input image의 size를 압축할 수 있었다.



## 참고문헌
- David Silver, Aja Huang, Chris J. Maddison, Arthur Guez, Laurent Sifre, George Van Den Driessche, . . . Demis Hassabis. (2016). Mastering the game of Go with deep neural networks and tree search. Nature, 529(7587), 484-489.
