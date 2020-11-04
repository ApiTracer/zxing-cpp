/*
* Copyright 2016 Huy Cuong Nguyen
* Copyright 2006 Jeremias Maerki.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "DMDefaultPlacement.h"
#include "ByteArray.h"

#include <cstdint>
#include <vector>

namespace ZXing::DataMatrix {

BitMatrix BitMatrixFromCodewords(const ByteArray& codewords, int width, int height)
{
	BitMatrix result(width, height);

	auto codeword = codewords.begin();

	auto visited = VisitMatrix(height, width, [&codeword, &result](const BitPosArray& bitPos) {
		// Places the 8 bits of a corner or the utah-shaped symbol character in the result matrix
		uint8_t mask = 0x80;
		for (auto& p : bitPos) {
			if (*codeword & mask)
				result.set(p.col, p.row);
			mask >>= 1;
		}
		++codeword;
	});

	if (codeword != codewords.end())
		return {};

	// Lastly, if the lower righthand corner is untouched, fill in fixed pattern
	if (!visited.get(width - 1, height - 1)) {
		result.set(width - 1, height - 1);
		result.set(width - 2, height - 2);
	}

	return result;
}

} // namespace ZXing::DataMatrix
