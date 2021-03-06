/**
 * Copyright (c) 2011-2017 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_CHILD_CLOSURE_CALCULATOR_HPP
#define LIBBITCOIN_CHILD_CLOSURE_CALCULATOR_HPP

#include <deque>
#include <bitcoin/blockchain/pools/stack_evaluator.hpp>
#include <bitcoin/blockchain/pools/transaction_pool_state.hpp>

namespace libbitcoin {
namespace blockchain {

class child_closure_calculator : public stack_evaluator
{
public:

    child_closure_calculator(transaction_pool_state& state);

    transaction_entry::list get_closure(transaction_entry::ptr tx);

protected:
    virtual bool visit(transaction_entry::ptr element);

private:
    transaction_pool_state& state_;
    transaction_entry::list closure_;
};

} // namespace blockchain
} // namespace libbitcoin

#endif
