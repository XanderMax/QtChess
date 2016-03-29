#include "KingState.h"

#include <iostream>

#include "../boards/BoardBase.h"



std::bitset<CELLS> KingState::getRegularMoves(int row, int col, const BoardBase &) const
{
    std::bitset<CELLS> moves;

    if(col >= 0 && col < COLS && row >= 0 && row < ROWS)
    {
        if(col > 0)
        {
            moves.set(INDEX(row, col - 1));

            if(row > 0)
            {
                moves.set(INDEX(row - 1, col - 1));
            }

            if(row < ROWS - 1)
            {
                moves.set(INDEX(row + 1, col - 1));
            }
        }

        if(col < COLS - 1)
        {
            moves.set(INDEX(row, col + 1));

            if(row > 0)
            {
                moves.set(INDEX(row - 1, col + 1));
            }

            if(row < ROWS - 1)
            {
                moves.set(INDEX(row + 1, col + 1));
            }
        }

        if(row > 0)
        {
            moves.set(INDEX(row - 1, col));

        }

        if(row < ROWS - 1)
        {
            moves.set(INDEX(row + 1, col));
        }
    }

    return moves;
}

std::bitset<CELLS> KingState::getCellsToMove(int row, int col, const BoardBase &board) const
{
    std::bitset<CELLS> moves;


    //For castling
    if(getPieceParty() == PieceParty::WHITE)
    {
        if(!isMoved())
        {
            //Castling for white to right rook
            if(board.getPieceTypeAt(_F8_) == PieceType::NONE
                    && board.getPieceTypeAt(_G8_) == PieceType::NONE
                    && board.getPieceTypeAt(_H8_) == PieceType::ROOK
                    && board.getPiecePartyAt(_H8_) == PieceParty::WHITE
                    && board.getIsMovedAt(_H8_))
            {
                moves.set(_G8_);
            }

            //Castling for white to left rook
            if(board.getPieceTypeAt(_B8_) == PieceType::NONE
                    && board.getPieceTypeAt(_C8_) == PieceType::NONE
                    && board.getPieceTypeAt(_D8_) == PieceType::NONE
                    && board.getPieceTypeAt(_A8_) == PieceType::ROOK
                    && board.getPiecePartyAt(_A8_) == PieceParty::WHITE
                    && board.getIsMovedAt(_A8_))
            {
                moves.set(_C8_);
            }
        }
    }
    else if(getPieceParty() == PieceParty::BLACK)
    {
        if(!isMoved())
        {
            if(!isMoved())
            {
                //Castling for black to right rook
                if(board.getPieceTypeAt(_F1_) == PieceType::NONE
                        && board.getPieceTypeAt(_G1_) == PieceType::NONE
                        && board.getPieceTypeAt(_H1_) == PieceType::ROOK
                        && board.getPiecePartyAt(_H1_) == PieceParty::WHITE
                        && board.getIsMovedAt(_H1_))
                {
                    moves.set(_G1_);
                }

                //Castling for black to left rook
                if(board.getPieceTypeAt(_B8_) == PieceType::NONE
                        && board.getPieceTypeAt(_C1_) == PieceType::NONE
                        && board.getPieceTypeAt(_D1_) == PieceType::NONE
                        && board.getPieceTypeAt(_A1_) == PieceType::ROOK
                        && board.getPiecePartyAt(_A1_) == PieceParty::WHITE
                        && board.getIsMovedAt(_A1_))
                {
                    moves.set(_G1_);
                }
            }
        }
    }

    return moves | getRegularMoves(row, col, board);
}


std::bitset<CELLS> KingState::getCellsToAttack(int row, int col, const BoardBase &board) const
{
    return getRegularMoves(row, col, board);
}

