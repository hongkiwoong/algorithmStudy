

/*
	정리 : 피봇을 정하고 피봇을 기준으로 작은 수는 왼쪽, 큰 수는 오른쪽에 위치시킨다. 
		   그리고 왼쪽 데이터에서 피봇, 오른쪽 데이터에서 피봇을 설정해 위의 과정을 정렬이 완료될 때까지 반복한다.

	장점 : 이름처럼 빠른 정렬이다. 
		   빠르지만, 최악의 경우 n^2의 시간이 걸릴 수 있다. 하지만 매 분할때 가장 앞쪽의 수가 선택되야 되므로 랜덤하게 피봇을 선택하면 
		   분할마다 최악의 피봇이 선택되는 확률은 매우 낮기 때문에 평균 1.39 nlogn

	단점 : 코드 구현을 재귀호출로 구현했을 때는 오버헤드가 크기 때문에 데이터가 클 경우 문제가 될 수 있다.
	       재귀호출이 아닌 반목문과 스택 자료구조를 활용하여 이 문제를 해결 할 수 있다.
*/