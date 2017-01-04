/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_BLOCKCHAIN_POPULATE_TRANSACTION_HPP
#define LIBBITCOIN_BLOCKCHAIN_POPULATE_TRANSACTION_HPP

#include <cstddef>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/blockchain/define.hpp>
#include <bitcoin/blockchain/interface/fast_chain.hpp>
#include <bitcoin/blockchain/populate/populate_base.hpp>

namespace libbitcoin {
namespace blockchain {

/// This class is NOT thread safe.
class BCB_API populate_transaction
  : public populate_base
{
public:
    populate_transaction(threadpool& pool, const fast_chain& chain);

    /// Populate validation state for the transaction.
    void populate(transaction_const_ptr tx, result_handler&& handler) const;

protected:
    void populate_inputs(const chain::transaction& tx, size_t chain_height,
        size_t bucket, size_t buckets, result_handler handler) const;
};

} // namespace blockchain
} // namespace libbitcoin

#endif
