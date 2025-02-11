# Colorado AI Meetups

## Denver Area AI Thought Leaders Forum

### Oct 2023: Generative AI Traps for the Unweary: Lessons Learned from over 130 Use Cases

Hosted By: Rob Taylor and Vince Allen of Carstens, Allen, and Gourley LLP

#### General Takeaways

* Integrate Compliance as part of the design process
* Notice of Disclosure is necessary for integrating AI Models
* Debunking Myths of AI
  * Anonymizing data is not enough to justify using data without user consent
  * Data lakes are not good to have around; they could be violating user rights by being outside the license of the original intent
* State of AI Regulation Laws
  * EU AI Act: Europe is taking a firm, prescriptive, paternalistic approach to AI laws
  * US doesn't have AI laws officially (...yet?)
    * Introducing Sweeping Regulation runs the risk of choking out innovation
* Treat AI Propmts for products as IP
* To intercept models for high stakes hallucinations, you could introduce significant guardrails and implement an allowlist strategy for the questions it is allowed to answer, vs the questions that it needs to refer to a human representative
* Employers are legally responsible for AI results and answers, similarly to how they would be liable for an employees actions. Similar supervision and training should be applied when onboarding (creating a new model) as well
* Due Dilligence is necessary before AI is integrated into a product: everyone is liable when something goes wrong
* Governement representatives are going after bold claims
* Prepare by having detailed, defensible, audit trails
* Beware of legal implications of AI Washing

#### Interesting Legal Cases

* [Patagonia](https://www.cxtoday.com/contact-centre/talkdesk-customer-patagonia-sued-over-its-use-of-contact-center-ai/) recorded and trained AI on employee HR calls without their consent. "This call may be recorded" message was deemed not sufficient
* [GM Financial](https://www.justice.gov/opa/pr/gm-financial-pay-over-35-million-resolve-servicemembers-civil-relief-act-claims): Collected driving data of Onstar users with the intent of selling it to insurance companies. Data was not anonymized
* [Ken Paxton](https://www.texasattorneygeneral.gov/news/releases/attorney-general-ken-paxton-reaches-settlement-first-its-kind-healthcare-generative-ai-investigation_), Texas AG filed a suit against a Texas based Healthcare AI Company to challenge their claims of dramatically low AI hallucination rates
* [Air Canada Bereavement Policy Hallucination](https://aibusiness.com/nlp/air-canada-held-responsible-for-chatbot-s-hallucinations-): The AI made up information about a bereavement policy that was inconsistent with the company policy, and had to pay back the customer for their ticket since AI misled them.
* [Jason Allen AI Art Competition](https://www.cpr.org/2023/09/06/jason-allens-ai-art-won-colorado-fair-feds-deny-copyright-protection/): In Colorado for a State Fair, he submitted an AI Image to the Digital Art Category. Won, but was denied prize when it was revealed the image was generated with AI. As his image is being shared, he wanted to copyright it. His claim for copyrighting the image was denied, but an option moving forward was that he could potentially copyright the 600+ prompts he used to generate the image.
  * Opens up an interesting ownership question: who is the artist? Is AI a tool like photoshop? His work is unreproducible due to the nature of AI's non-determinism
  * Similar discussion to the [Nike Selfie Monkey](https://www.npr.org/sections/thetwo-way/2017/09/12/550417823/-animal-rights-advocates-photographer-compromise-over-ownership-of-monkey-selfie): The camera is the tool, the photographer is the artist. But when a monkey takes the photo, who owns the image or can file a copyright claim for it? PETA sued on behalf of the monkey, It was ruled that only humans can have copyright rights
  * Discussions are still ongoing around whether the images that the AI trained on in order to generate the resulting art piece is "Fair Use"
* [AI Washing](https://www.debevoise.com/insights/publications/2024/04/the-increasing-risks-of-ai-washing-and-securities): Claiming that something is AI when it is really people offshore analyzing info, and this violates the Advertising Standards Committee code of conduct, among other things
  * [Amazon](https://www.bbc.com/news/articles/c9xx8122893o) Accusations that ["just walk out"](https://www.theverge.com/2024/4/17/24133029/amazon-just-walk-out-cashierless-ai-india) purchases are calculated by people watching you shop
  * [Cosmetics Example](https://www.legaldive.com/news/questions-over-ai-claims-lawsuits-securities-laws-lacroix-oddity-ai-washing/722152/)

#### Further Reading, Rabbit Holes, and Resources

* MIT Study 777
* incidentdatabase.ai is a click-baity list of AI Compliance/Legal incidents
* Deceptive Trade Processes Act
* Fair Competition
* FTC Guidance: "Keep your AI Claims in Check"
* AI Washing
* Failures to Inform Consumers of rights is negligence
* Hallucination rates of models
* Gartner is a good resource for compiled statistics
* Emotion Sentiment Analysis


## Denver AI Group Meetup

### Jan 21 2025 Workshop

#### Notes

* Specific Tools for Agentic AI
  * Tip: Pick tool that is actively being maintained
  * microsoft autogen
  * llama index workflow
  * sglang
  * dsp
  * swarm
  * langraph
    * Can use langraph as a dependency
    * Still Python libraries
    * langgraph RAG use case
  * langchain = block based
  * langsmith
  * huggingface for open source API for AI, need a GPU to do it
  * Docker: can be a way to get the UI to work
  * ollama is open source
  * Tavily for python searching
  * Jupyter workbook for prototyping
  * Alpha Vantage
* Strategies
  * Human in the loop
  * Prompt Routing
  * Decision trees for what the agent has to work through
  * Prompt Input -> Switch to tokens -> Throw into LLM
  * 2 types of agentic apps
* Resources to get good
  * Langchain course on Coursera
  * Ask GPT on how it works, interview it
* Guiding Questions for Product Development from Erik P.
  * What are the stimuli? (e.g. google alerts)
  * What data am I going to want to access? (e.g. SEC filings, stock prices)
  * What do I want to learn from that data?
  * What do I want to do with what I learn?
* Lessons Learned from the resident experts
  * Every use case that relies on LLMs as the agent is a complex one because it is so bad at it
  * LLM call is more edpensive than running a script
  * DAGs are bad at handling replanning
  * Hardest part is the data access and toolset

#### Agentic Stock Market Use Case Notes

* Stimulus: access data, SSE filngs, what do you want to get out of it
* Agent step in a chain of a more complex workflow
* What do you want to learn
* Good value play, undervalued, overvalued
* RAG Workflow: fgather a bunch of data, put into the context window, see if there is a langchain plugin for bloomberg
* Langgraph, these are tools I want to give access to
* Option picker

Agentic Use Case

* AI app that takes an action in the real world (Ex: Buy and sell a stock), provide a use case
  * Can stand up a technical analysis toolkit
* Human Assistant thing = step 1 of an agent
  * Analyze these, see if there is a buy, sell, sell short thing
* Uses model as a reasoning model
* AutoGPT failed asa loop
* DAGs, directed acyclic graphs
* Microsoft Autogen and llama index are event driven agentic workflows
* Chron Job that runs
* Chain vs agent that takes action
* Bounding what GPT is doing, really specializing it
* What is stimulus:
  * News story on a specific stock or a category
* Example: sending email would be the agentic action, could do it at the end automatically
* Chain is analagous to an ETL
