/*
 *	 TwitCrusader++ - Twitter Client For Linux Desktop
 *		Copyright (C) 2011  TwitCrusader++
 *
 *		This program is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		This program is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *		Source: https://github.com/RoxShannon/TwitCrusaderpp
 *		email: orazio.1985@hotmail.com
 *
 */

#include "include/TimeLine.h"

namespace TwitCrusader {

vector<Tweet> TwitCrusader::TimeLine::readTimeLine(string fileName)
{

	vector<Tweet> timeline=vector<Tweet>();
	DomParser parser;
	parser.set_substitute_entities();
	parser.parse_file(fileName);
	if(parser)
	{
		const Node* rootNode = parser.get_document()->get_root_node();
		const ustring rootName = rootNode->get_name();

		cout<<rootName<<endl;

		Node::NodeList status=rootNode->get_children("status");

		for(Node::NodeList::iterator i=status.begin(); i!=status.end(); ++i){
			ustring statusname(i.operator *()->get_name());

			cout<<"statusname:\t"<<statusname<<endl;

			Node::NodeList tweet=i.operator *()->get_children();

			for(Node::NodeList::iterator j=tweet.begin(); j!=tweet.end(); ++j){

				ustring tweetname(j.operator *()->get_name());

				cout<<"tweetname:\t"<<tweetname<<endl;

				if(tweetname.compare("user")==0){

					Node::NodeList usr=j.operator *()->get_children();

					for(Node::NodeList::iterator z=usr.begin(); z!=usr.end(); ++z){
						ustring username(z.operator *()->get_name());
						cout<<"username:\t"<<username<<endl;
					}
					cout<<"end username"<<endl<<endl;
				}
				cout<<"end tweet"<<endl<<endl;
			}

			cout<<"end status"<<endl<<endl;
		}


	}

	return timeline;
}

} /* namespace TwitCrusader */
