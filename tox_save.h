#ifndef TOX_SAVE_H_
#define TOX_SAVE_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

/**
 * Toxcore save file parser (wip)
 */

class tox_save_t : public kaitai::kstruct {

public:
    class state_t;
    class state_name_t;
    class state_groups_t;

    enum state_type_t {
        STATE_TYPE_NOSPAMKEYS = 1,
        STATE_TYPE_DHT = 2,
        STATE_TYPE_FRIENDS = 3,
        STATE_TYPE_NAME = 4,
        STATE_TYPE_STATUSMESSAGE = 5,
        STATE_TYPE_STATUS = 6,
        STATE_TYPE_GROUPS = 7,
        STATE_TYPE_TCP_RELAY = 10,
        STATE_TYPE_PATH_NODE = 11,
        STATE_TYPE_CONFERENCES = 20,
        STATE_TYPE_END = 255
    };

    tox_save_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, tox_save_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~tox_save_t();

    class state_t : public kaitai::kstruct {

    public:

        state_t(kaitai::kstream* p__io, tox_save_t* p__parent = 0, tox_save_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~state_t();

    private:
        uint32_t m_sub_length;
        state_type_t m_type;
        std::string m_cookie;
        kaitai::kstruct* m_data;
        bool n_data;

    public:
        bool _is_null_data() { data(); return n_data; };

    private:
        tox_save_t* m__root;
        tox_save_t* m__parent;
        std::string m__raw_data;
        kaitai::kstream* m__io__raw_data;

    public:
        uint32_t sub_length() const { return m_sub_length; }
        state_type_t type() const { return m_type; }
        std::string cookie() const { return m_cookie; }
        kaitai::kstruct* data() const { return m_data; }
        tox_save_t* _root() const { return m__root; }
        tox_save_t* _parent() const { return m__parent; }
        std::string _raw_data() const { return m__raw_data; }
        kaitai::kstream* _io__raw_data() const { return m__io__raw_data; }
    };

    class state_name_t : public kaitai::kstruct {

    public:

        state_name_t(kaitai::kstream* p__io, tox_save_t::state_t* p__parent = 0, tox_save_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~state_name_t();

    private:
        std::string m_name;
        tox_save_t* m__root;
        tox_save_t::state_t* m__parent;

    public:
        std::string name() const { return m_name; }
        tox_save_t* _root() const { return m__root; }
        tox_save_t::state_t* _parent() const { return m__parent; }
    };

    class state_groups_t : public kaitai::kstruct {

    public:

        state_groups_t(kaitai::kstream* p__io, tox_save_t::state_t* p__parent = 0, tox_save_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~state_groups_t();

    private:
        std::string m_pack;
        tox_save_t* m__root;
        tox_save_t::state_t* m__parent;

    public:
        std::string pack() const { return m_pack; }
        tox_save_t* _root() const { return m__root; }
        tox_save_t::state_t* _parent() const { return m__parent; }
    };

private:
    std::string m_magic;
    std::vector<state_t*>* m_states;
    tox_save_t* m__root;
    kaitai::kstruct* m__parent;

public:
    std::string magic() const { return m_magic; }
    std::vector<state_t*>* states() const { return m_states; }
    tox_save_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // TOX_SAVE_H_
