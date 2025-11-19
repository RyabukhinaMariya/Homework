import pytest
from hypothesis import strategies, given, settings, HealthCheck
from contextlib import nullcontext

from Heap_sort import heap_sort


class TestSort:
    @pytest.mark.parametrize(
        "arr, res, expectations",
        [

            ([3, 2, 4, 1, 5], [1, 2, 3, 4, 5], nullcontext()),
            ([1, 6, "t", 7, 3], [1, 3, 6, 7, "t"], pytest.raises(TypeError))
        ]
    )
    def test_sort(self, arr, res, expectations):
        with expectations:
            assert heap_sort(arr) == res

class TestEdgeCases:
    @pytest.mark.parametrize(
        "edge_arr, edge_res",
        [
            ([], []),
            ([1], [1]),
            ([2, 1], [1, 2]),
            ([1, 2, 3], [1, 2, 3]),
            ([4, 3, 2, 1], [1, 2, 3, 4]),
            ([4, 4, 4, 4], [4, 4, 4, 4]),
            ([1, 7, 2, 6, 3, 5, 4], [1, 2, 3, 4, 5, 6, 7]),
            ([4, 1, 5, 2, 6, 3, 7], [1, 2, 3, 4, 5, 6, 7]),
            ([-1, -2, 0, -5, -8, -3], [-8, -5, -3, -2, -1, 0]),
            ([1, 0.5, 0.6, 0.3, 2], [0.3, 0.5, 0.6, 1, 2]),
            ([float('inf'), -float('inf'), 1e100, -1e100], [-float('inf'), -1e+100, 1e+100, float('inf')])
        ]
    )
    def test_boundary_cases(self, edge_arr, edge_res):
        assert heap_sort(edge_arr) == edge_res

class PBT:
    @given(strategies.lists(strategies.decimals(), max_size=100))
    @settings(max_examples=100, suppress_health_check=[HealthCheck.too_slow])
    def test_pbt(self, arr):
        sorted_arr = heap_sort(arr)
        assert all(sorted_arr[i] - sorted_arr[i-1] > 0 for i in range(1, len(sorted_arr)))



