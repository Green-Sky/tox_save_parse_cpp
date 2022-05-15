#include "json.hpp"

#include "tox_save.h"

#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "missing tox save\n";
		return -1;
	}

	std::ifstream tox_file{argv[1]};
	kaitai::kstream kstr{&tox_file};

	const tox_save_t tox_save {&kstr};

	for (const auto* state : *tox_save.states()) {
		std::cout << "state: " << state->type() << "\n";
		switch (state->type()) {
			case tox_save_t::STATE_TYPE_NAME:
				std::cout << "  name: " << static_cast<tox_save_t::state_name_t*>(state->data())->name() << "\n";
				break;
			case tox_save_t::STATE_TYPE_GROUPS:
				{
					auto* state_groups = static_cast<tox_save_t::state_groups_t*>(state->data());
					auto groups_j = nlohmann::json::from_msgpack(state_groups->pack());
					std::cout << "  groups_j: " << groups_j.dump(2) << "\n";
				}
				break;

			default:
				break;
		}
	}

	return 0;
}

