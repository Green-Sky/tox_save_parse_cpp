// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "tox_save.h"
#include "kaitai/exceptions.h"

tox_save_t::tox_save_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, tox_save_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_states = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tox_save_t::_read() {
    m_magic = m__io->read_bytes(8);
    if (!(magic() == std::string("\x00\x00\x00\x00\x1F\x1B\xED\x15", 8))) {
        throw kaitai::validation_not_equal_error<std::string>(std::string("\x00\x00\x00\x00\x1F\x1B\xED\x15", 8), magic(), _io(), std::string("/seq/0"));
    }
    m_states = new std::vector<state_t*>();
    {
        int i = 0;
        state_t* _;
        do {
            _ = new state_t(m__io, this, m__root);
            m_states->push_back(_);
            i++;
        } while (!( ((_->type() == tox_save_t::STATE_TYPE_END) || (_io()->is_eof())) ));
    }
}

tox_save_t::~tox_save_t() {
    _clean_up();
}

void tox_save_t::_clean_up() {
    if (m_states) {
        for (std::vector<state_t*>::iterator it = m_states->begin(); it != m_states->end(); ++it) {
            delete *it;
        }
        delete m_states; m_states = 0;
    }
}

tox_save_t::state_t::state_t(kaitai::kstream* p__io, tox_save_t* p__parent, tox_save_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m__io__raw_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tox_save_t::state_t::_read() {
    m_sub_length = m__io->read_u4le();
    m_type = static_cast<tox_save_t::state_type_t>(m__io->read_u2le());
    m_cookie = m__io->read_bytes(2);
    if (!(cookie() == std::string("\xCE\x01", 2))) {
        throw kaitai::validation_not_equal_error<std::string>(std::string("\xCE\x01", 2), cookie(), _io(), std::string("/types/state/seq/2"));
    }
    n_data = true;
    switch (type()) {
    case tox_save_t::STATE_TYPE_NAME: {
        n_data = false;
        m__raw_data = m__io->read_bytes(sub_length());
        m__io__raw_data = new kaitai::kstream(m__raw_data);
        m_data = new state_name_t(m__io__raw_data, this, m__root);
        break;
    }
    case tox_save_t::STATE_TYPE_GROUPS: {
        n_data = false;
        m__raw_data = m__io->read_bytes(sub_length());
        m__io__raw_data = new kaitai::kstream(m__raw_data);
        m_data = new state_groups_t(m__io__raw_data, this, m__root);
        break;
    }
    default: {
        m__raw_data = m__io->read_bytes(sub_length());
        break;
    }
    }
}

tox_save_t::state_t::~state_t() {
    _clean_up();
}

void tox_save_t::state_t::_clean_up() {
    if (!n_data) {
        if (m__io__raw_data) {
            delete m__io__raw_data; m__io__raw_data = 0;
        }
        if (m_data) {
            delete m_data; m_data = 0;
        }
    }
}

tox_save_t::state_name_t::state_name_t(kaitai::kstream* p__io, tox_save_t::state_t* p__parent, tox_save_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tox_save_t::state_name_t::_read() {
    m_name = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("UTF-8"));
}

tox_save_t::state_name_t::~state_name_t() {
    _clean_up();
}

void tox_save_t::state_name_t::_clean_up() {
}

tox_save_t::state_groups_t::state_groups_t(kaitai::kstream* p__io, tox_save_t::state_t* p__parent, tox_save_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tox_save_t::state_groups_t::_read() {
    m_pack = m__io->read_bytes_full();
}

tox_save_t::state_groups_t::~state_groups_t() {
    _clean_up();
}

void tox_save_t::state_groups_t::_clean_up() {
}
