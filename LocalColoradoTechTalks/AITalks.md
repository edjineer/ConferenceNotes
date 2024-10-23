# Colorado AI Meetups

## Denver Area AI Thought Leaders Forum

### Oct 2023: Generative AI Traps for the Unweary: Lessons Learned from over 130 Use Cases

Hosted By: Rob Taylor and Vince Allen of Carstens, Allen, and Gourley LLP

#### General Takeaways

* Integrate Compliance as part of the design process
* Notice of Disclosure is necessary for integrating AI Models
* Myths of AI Debunked
  * Anonymizing data is not enough
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

#### Interesting Legal Cases

* [Patagonia](https://www.cxtoday.com/contact-centre/talkdesk-customer-patagonia-sued-over-its-use-of-contact-center-ai/) recorded and trained AI on employee HR calls without their consent. "This call may be recorded" message was not sufficient
* [GM Financial](https://www.justice.gov/opa/pr/gm-financial-pay-over-35-million-resolve-servicemembers-civil-relief-act-claims): Collected driving data of Onstar users with the intent of selling it to insurance companies. Data was not anonymized
* [Ken Paxton](https://www.texasattorneygeneral.gov/news/releases/attorney-general-ken-paxton-reaches-settlement-first-its-kind-healthcare-generative-ai-investigation_), Texas AG filed a suit against a Texas based Healthcare AI Company to challenge their claims of dramatically low AI hallucination rates
* [Air Canada Bereavement Policy Hallucination](https://aibusiness.com/nlp/air-canada-held-responsible-for-chatbot-s-hallucinations-): The AI made up information about a bereavement policy that was inconsistent with the company policy, and had to pay back the customer for their ticket since AI misled them.
* [Jason Allen AI Art Competition](https://www.cpr.org/2023/09/06/jason-allens-ai-art-won-colorado-fair-feds-deny-copyright-protection/): In Colorado for a State Fair, he submitted an AI Image to the Digital Art Category. Won, but was denied prize when it was revealed the image was generated with AI. As his image is being shared, he wanted to copyright it. His claim for copyrighting the image was denied, but an option moving forward was that he could potentially copyright the 600+ prompts he used to generate the image.
  * Opens up an interesting ownership question: who is the artist? Is AI a tool like photoshop? His work is unreproducible due to the nature of AI's non-determinism
  * Similar discussion to the [Nike Selfie Monkey](https://www.npr.org/sections/thetwo-way/2017/09/12/550417823/-animal-rights-advocates-photographer-compromise-over-ownership-of-monkey-selfie): The camera is the tool, the photographer is the artist. But when a monkey takes the photo, who owns the image or can file a copyright claim for it? PETA sued on behalf of the monkey, It was ruled that only humans can have copyright rights

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


