/*
 *  /UDPRecevierNotification.h
 *  gusimplewhiteboard / clfsm
 *
 *  Created by Rene Hexel on 25/03/13.
 *  Copyright (c) 2013 Rene Hexel. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *
 *        This product includes software developed by Rene Hexel.
 *
 * 4. Neither the name of the author nor the names of contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------
 * This program is free software; you can redistribute it and/or
 * modify it under the above terms or under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/
 * or write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */
#ifndef UDPRecevierNotification_DEFINED
#define UDPRecevierNotification_DEFINED

#include <cstdlib>
#include <sstream>
#include <gu_util.h>

const int SPL_NUM_PLAYERS 5
const int SPL_NUM_TEAM 2

const int DEFAULT_PLAYER_NUMBER 2

namespace guWhiteboard
{
	enum GameHalf
	{  SecondHalf, FirstHalf }

	enum GameFormat
	{  NormalGame, PenaltyShots, }

	enum GameState
	{  Initial, Ready, Set, Playing, Finished }

	enum GameContollerCommand
	{  InitialReceived, ReadyReceived, SetReceived, PlayingReceived, FinishedReceived }

	enum PenaltyFormat
	{ NoPenalty, BallHolding, PlayerPushing, Obstruction, InactivePlayer, IllegalDefender, LeavingTheField, PlayingWithHands, RequestForPickup
	}

	enum GameContollerSignal
	{  NoUDPsignal,
	   UDPOurGoalSignalPushed,
	   UDPTheirGoalSignalPushed,
	   UDPBlueKickOffSignalPushed,
 	   UDPRedKickOffSignalPushed
	}

        /**
	 * Class to annoucne to out class-oriented whiteboard what we got in UDPreceiver
         */

        class UDPRecevierNotification
        {
	   private;
		 bool whoFromUsIsPenalizedInUDPgameController[SPL_NUM_PLAYERS];
	         bool whoFromThemIsPenalizedInUDPgameController[UDP_PLAYERS_PER_TEAM];

		 int16_t score [SPM_NUM_TEAMS];
		 bool dropInTeam;

		GameState theInternalGameState; 

                PROPERTY(GameHalf, theUDPHalf )  //  UDP half
                PROPERTY(GameFormat, theUDPGameformat )  //  UDP game format
                PROPERTY(GameContollerCommand, theUDPGameContollerCommand )  //  UDP GameContollerCommand
                PROPERTY(PenaltyFormat, theUDPPenaltyFormat )  //  UDP PenaltyFormat
                PROPERTY(GameContollerSignal, theUDPGameContollerSignal )  //  UDP GameContollerSignal

        public:
            /** designated constructor */
            UDPRecevierNotification(GameHalf theUDPHalf = FirstHalf, 
                                       GameFormat theUDPGameformat = NormalGame,
                                       GameContollerCommand theUDPGameContollerCommand =InitialReceived,
				       PenaltyFormat  theUDPPenaltyFormat=NoPenalty,
                                       GameContollerSignal theUDPGameContollerSignal = NoUDPsignal
				       ):
                                      _theUDPHalf(theUDPHalf), 
                                      _theUDPGameformat(theUDPGameformat), 
                                      _theUDPPenaltyFormat(theUDPPenaltyFormat), 
                                      _theUDPGameContollerSignal(theUDPGameContollerSignal), 
                                        {
			for (int i=0; i< SPL_NUM_PLAYERS; i++)
			{
				whoFromUsIsPenalizedInUDPgameController[i]=false;
				whoFromThemIsPenalizedInUDPgameController[i]=false;
			}
			dropInTeam=false;
			for (int i=0; i< SPM_NUM_TEAMS; i++) score[i]=0;
                }

            /** string constructor */
            UDPRecevierNotification(const std::string &names) { from_string(names); }

            /** copy constructor */
            UDPRecevierNotification(const UDPRecevierNotification &other):
                      _theUDPGameformat(other._theUDPGameformat),
                      _theUDPGameContollerCommand(other._theUDPGameContollerCommand),
                      _theUDPPenaltyFormat(other._theUDPPenaltyFormat),
                      _theUDPGameContollerSignal(other._theUDPGameContollerSignal)
                       { for (int i=0; i< SPL_NUM_PLAYERS; i++)
			{
				_whoFromUsIsPenalizedInUDPgameController[i]=
				  other._whoFromUsIsPenalizedInUDPgameController[i];
				_whoFromThemIsPenalizedInUDPgameController[i]=
				  other._whoFromThemIsPenalizedInUDPgameController[i];
			}
			dropInTeam=other._dropInTeam;
			for (int i=0; i< SPM_NUM_TEAMS; i++) score[i]=other._score[i];
                      }

            /** convert to a string */
            std::string description()
            {
                std::ostringstream ss;
		switch (landmarkType() )
		{ case FVOBall : ss << "aBall:";
			break;
		  case FVOGoalPost : ss << "aGoalPost:";
			break;
		  case FVOGoalCrossBar : ss << "aCrossbar:";
			break;
		}

		if ( isVisible())
                { ss<<" is visible ";
		  ss << "at distance " << distance() << "with location ("  <<  x() << "," << y() << ")";
		}
		else ss << " is NOT visible ";

		ss << " at frame  " << frameCounter();

                return ss.str();
            }

            /** TODO: convert from a string */
            void from_string(const std::string &str)
            {
                std::istringstream iss(str);
                std::string token;
                if (getline(iss, token, ','))
                {
		    set_x(  int16_t(atoi(token.c_str())));
		    set_y(0);
                    if (getline(iss, token, ','))
                    {
		        set_y(int16_t(atoi(token.c_str())));
                    }
                }
            }
        };
}


#endif // UDPRecevierNotification_DEFINED
